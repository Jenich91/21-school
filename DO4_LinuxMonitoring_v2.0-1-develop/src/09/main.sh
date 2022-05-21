#!/bin/bash
# sudo mkdir /var/www/html/metrics
# sudo touch /var/www/html/metrics/index.html

function GetPage {
    CpuUsage=`sudo cat /proc/stat| sed -n 1p | awk '{print $2}'`
    MemFree=`free -m | sed -n 2p | awk '{print $4}'`
    DiskTotal=`df -m / | sed -n 2p | awk '{print $3+$4}'`

    echo "
    node_cpu_seconds_total $CpuUsage
    node_memory_MemFree_bytes $MemFree
    node_filesystem_size_bytes $DiskTotal
    "
}
while true ; do
    # echo "Step by step"
    GetPage > /var/www/html/metrics/index.html
    sleep 3
done

#open vbox port, nat
#sudo nano /etc/nginx/sites-enabled/default
    # (edit line -> root /var/www/html/metrics; server_name sfleta; index index.html;)
#sudo service nginx restart
#sudo bash main.sh

#prometeus conf -> sudo nano /etc/prometheus/prometheus.yml

    # node_cpu_seconds_total{cpu="0",mode="idle"} $CpuUsage
    # node_memory_MemFree_bytes[] $MemFree
    # node_filesystem_size_bytes{device="/dev/sda2",fstype="ext4",mountpoint="/"} $DiskTotal