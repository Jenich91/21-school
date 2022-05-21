sudo apt install prometheus
sudo nano /etc/prometheus/prometheus.yml
sudo useradd --no-create-home --shell /bin/false prometheus
sudo systemctl edit --full --force prometheus.service
sudo systemctl start prometheus
sudo systemctl status prometheus
