#!/usr/bin/env bash
#
# 東方故事 MUD —— 一鍵啟動／管理開發用 docker 容器
#
# 用法：
#   ./run.sh              啟動（映像不存在會自動 build），並顯示連線方式
#   ./run.sh start        同上
#   ./run.sh stop         正常關閉（SIGTERM，driver 會存檔）並移除容器
#   ./run.sh restart      重啟（改了 simul_efun / master 之後要用這個）
#   ./run.sh kill         強制砍掉（SIGKILL，不存檔，只在 driver 卡死時用）
#   ./run.sh build        （重新）建置映像
#   ./run.sh logs         跟著看 driver 的 stdout
#   ./run.sh debug        跟著看 log/debug.log（執行時段錯誤）
#   ./run.sh telnet       在容器內開 telnet 連進 MUD
#   ./run.sh shell        進容器的 bash
#   ./run.sh status       看容器狀態
#
# 環境變數：PORT（預設 8888）、STOP_TIMEOUT（預設 30 秒）、IMAGE、TAG、NAME
#
set -euo pipefail

cd "$(dirname "${BASH_SOURCE[0]}")"

IMAGE=${IMAGE:-es-mud-fluffos}
TAG=${TAG:-2026.0901}
NAME=${NAME:-es-mud}
PORT=${PORT:-8888}
STOP_TIMEOUT=${STOP_TIMEOUT:-30}
CFG=/mudlib/etc/fluffos.cfg

have_image() { docker image inspect "$IMAGE:$TAG" >/dev/null 2>&1; }
container_exists() { [ -n "$(docker ps -aq -f name="^${NAME}$")" ]; }
container_running() { [ -n "$(docker ps -q -f name="^${NAME}$")" ]; }

do_build() {
  echo "==> 建置 $IMAGE:${TAG}（第一次要從 source 編 FluffOS，需要幾分鐘）"
  docker build -t "$IMAGE:$TAG" -f .devcontainer/Dockerfile .devcontainer
}

# 一定要走 SIGTERM。driver 收到 SIGTERM 才會呼叫 master 的 crash()，
# 進而 SHUTDOWN_D->do_shutdown() 存下 daemon 與所有線上玩家的資料。
# 這個 mudlib 沒有定時自動存檔（std/user.c 的 autosave_user() 是註解掉的），
# 直接 docker rm -f（SIGKILL）等於把上次存檔之後的經驗值全部丟掉。
do_stop() {
  if container_running; then
    echo "==> 關閉 ${NAME}（送 SIGTERM，等 driver 存檔）"
    docker stop -t "$STOP_TIMEOUT" "$NAME" >/dev/null
  fi
  container_exists && docker rm "$NAME" >/dev/null 2>&1 || true
}

do_start() {
  have_image || do_build
  if container_running; then
    echo "==> $NAME 已經在跑了"
  else
    container_exists && docker rm "$NAME" >/dev/null 2>&1
    echo "==> 啟動 ${NAME}（port ${PORT}）"
    docker run -d --name "$NAME" -p "${PORT}:8888" \
      -v "$PWD":/mudlib -w /mudlib \
      "$IMAGE:$TAG" driver "$CFG" >/dev/null
    sleep 2
  fi
  if ! container_running; then
    echo "!! 容器沒起來，最後的輸出："
    docker logs --tail 40 "$NAME" || true
    exit 1
  fi
  cat <<MSG

MUD 已啟動。連進去玩：

  ./run.sh telnet            （在容器內連，中文寬度正常）
  telnet 127.0.0.1 $PORT      （從 macOS 本機連，需自備 telnet）

帳號 admin / 12345。用 127.0.0.1，不要用 localhost —— driver 只綁 IPv4。
看錯誤：./run.sh debug（執行時段錯誤）、d/<領域>/log（編譯錯誤）。
MSG
}

case "${1:-start}" in
  start)   do_start ;;
  stop)    container_exists && { do_stop; echo "==> 已停止 $NAME"; } || echo "==> $NAME 沒在跑" ;;
  restart) do_stop; do_start ;;
  kill)    docker rm -f "$NAME" >/dev/null 2>&1 && echo "==> 已強制砍掉 $NAME（未存檔）" || echo "==> $NAME 沒在跑" ;;
  build)   do_build ;;
  logs)    docker logs -f --tail 100 "$NAME" ;;
  debug)   tail -f log/debug.log ;;
  telnet)  docker exec -it "$NAME" telnet 127.0.0.1 8888 ;;
  shell)   docker exec -it "$NAME" bash ;;
  status)  docker ps -a --filter "name=^${NAME}$" --format 'table {{.Names}}\t{{.Status}}\t{{.Ports}}' ;;
  -h|--help|help) sed -n '3,18p' "$0" | sed 's/^# \{0,1\}//' ;;
  *)       echo "不認得的指令：${1}（用 ./run.sh help 看用法）" >&2; exit 2 ;;
esac
