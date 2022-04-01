sudo raspi-config
raspi-config是树莓派系统自带的系统配置工具，简单好用且功能强大，没事建议多进去看看。


设置静态ip:手动编辑/etc/dhcpcd.conf文件，在文件最末加入类似的如下行：

interface eth0
inform 192.168.1.2
static routers=192.168.1.1
static domain_name_servers=114.114.114.114
static ip6_address=2409:8a00:78d8:10b0:9d9e:1193:c495:228f
src/gz openwrt_core https://downloads.openwrt.org/snapshots/targets/allwinner-h5/generic/packages
src/gz openwrt_base https://downloads.openwrt.org/snapshots/packages/aarch64_cortex-a53/base
src/gz openwrt_luci https://downloads.openwrt.org/snapshots/packages/aarch64_cortex-a53/luci
src/gz openwrt_packages https://downloads.openwrt.org/snapshots/packages/aarch64_cortex-a53/packages
src/gz openwrt_routing https://downloads.openwrt.org/snapshots/packages/aarch64_cortex-a53/routing
