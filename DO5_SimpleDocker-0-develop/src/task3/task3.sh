#!/bin/bash

docker pull nginx
docker run --name Server_taks3 -dt -p 81:81 nginx
docker exec -it Server_taks3 apt update
docker exec -it Server_taks3 apt install -y gcc libfcgi-dev spawn-fcgi
docker exec -it Server_taks3 mkdir /server
cd server
docker cp server.c Server_taks3:server/server.c
docker cp nginx.conf Server_taks3:etc/nginx/nginx.conf
docker exec Server_taks3 nginx -s reload
cd ..

docker exec Server_taks3 bash -c 'cd server;gcc server.c -lfcgi -o server'
docker exec Server_taks3 bash -c 'cd server;spawn-fcgi -p 8080 /server/server'
docker exec Server_taks3 bash -c 'service nginx start'
curl http://localhost:81
