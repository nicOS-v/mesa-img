#!/bin/bash

set -e
set -o xtrace

export DEBIAN_FRONTEND=noninteractive

cat >/etc/apt/sources.list <<EOF
deb http://$APT_MIRROR/debian bullseye main
deb http://$APT_MIRROR/debian-security bullseye-security main
deb http://$APT_MIRROR/debian bullseye-updates main
EOF

apt-get update
apt-get install -y --no-remove gnupg2 wget ca-certificates lsb-release software-properties-common

sed -i -e 's/http:\/\//https:\/\//g' /etc/apt/sources.list
