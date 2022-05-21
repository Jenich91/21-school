#!/bin/bash
# . ./myLib.sh

function GetWordStringFromArr {
    RandomString=($@)
    rand=$[$RANDOM % ${#@}]
    echo ${RandomString[rand]}
}

function GetStringStringFromArr {
    arr=("${!1}")
    echo ${arr[$[RANDOM % ${#arr[@]}]]}
}

# Написать bash-скрипт или программу на Си, генерирующий 5 файлов логов nginx в combined формате.
    # Каждый лог должен содержать информацию за 1 день. //  for all 5 day, with different dates
    # За день должно быть сгенерировано случайное число записей от 100 до 1000.
    # Для каждой записи должны случайным образом генерироваться:

# 1) IP (любые корректные, т.е. не должно быть ip вида 999.111.777.777)
function GetRandomIp {
    printf "%d.%d.%d.%d\n" "$((RANDOM % 256))" "$((RANDOM % 256))" "$((RANDOM % 256))" "$((RANDOM % 256))"
}

# 2) Коды ответа (200, 201, 400, 401, 403, 404, 500, 501, 502, 503)
    # Коды ответа:
    # 200 OK — успешный запрос. Если клиентом были запрошены какие-либо данные, то они находятся в заголовке и/или теле сообщения.
    # 201 Created — в результате успешного выполнения запроса был создан новый ресурс. 
    # 400 Bad Request — сервер обнаружил в запросе клиента синтаксическую ошибку. 
    # 401 Unauthorized — для доступа к запрашиваемому ресурсу требуется аутентификация. 
    # 403 Forbidden — сервер понял запрос, но он отказывается его выполнять из-за ограничений в доступе для клиента к указанному ресурсу.
    # 404 Not Found —  Сервер понял запрос, но не нашёл соответствующего ресурса по указанному URL. Основная причина — ошибка в написании адреса Web-страницы.
    # 500 Internal Server Error — любая внутренняя ошибка сервера, которая не входит в рамки остальных ошибок класса.
    # 501 Not Implemented — сервер не поддерживает возможностей, необходимых для обработки запроса.
    # 502 Bad Gateway — сервер, выступая в роли шлюза или прокси-сервера, получил недействительное ответное сообщение от вышестоящего сервера.
    # 503 Service Unavailable — сервер временно не имеет возможности обрабатывать запросы по техническим причинам (обслуживание, перегрузка и прочее).
ResponseCodes=(200 201 400 401 403 404 500 501 502 503)

# Методы (GET, POST, PUT, PATCH, DELETE)
RandomHTTPMetodArr=(GET POST PUT PATCH DELETE)
RandomExtArr=(7z A AAPKG AAC ace ALZ APK APPX AT3 bke ARC ARC ARJ ASS B BA BB big BIN bjsn BKF Blend bzip2 BMP bld cab c4 cals css html php js xaml CLIPFLAIR CPT DAA deb DMG DDZ DN DPE egg EGT ECAB ESD ESS EXE Flipchart GBP GBS GHO GIF gzip HTML IPG jar JPG JPEG LBR LBR LQR LHA lzip lzo lzma LZX MBW MHTML MPQ BIN NL2PKG NTH OAR OSK OSR OSZ PAK PAR PAF PEA PNG PHP PYK PK3 PK4 PXZ py RAR RAG RaX RBXL RBXLX RBXM RBXMX RPM sb sb2 sb3 SEN SIT SIS SKB SQ SWM SZS TAR TGZ TB TIB UHA UUE VIV VOL VSA WAX WIM XAP xz Z zoo zip ZIM)

# Даты (в рамках заданного дня лога, должны идти по увеличению)
function GetNextDate { # must like be 15/Oct/2019
    echo `shuf -n1 -i$(date -d '1991-01-01' '+%s')-$(date -d '2022-03-01' '+%s') | xargs -I{} date -d '@{}' '+%d/%^b/%Y' | sort`
}

function GetRandomTime {
   echo `date -d " $((RANDOM%12+1)):$((RANDOM%59+1)):$((RANDOM%59+1))" '+%H:%M:%S'`
}

# URL запроса агента
function GetRandomWord {
ALL_NON_RANDOM_WORDS=./wordlist
    non_random_words=`cat $ALL_NON_RANDOM_WORDS | wc -l`
    word=""
    while [[ -z $word || $word =~ ^\ +$ ]]; do
    random_number=`od -N3 -An -i /dev/urandom | awk -v f=0 -v r="$non_random_words" '{printf "%i\n", f + r * $1 / 16777216}'` 
    word=$(sed `echo $random_number`"q;d" $ALL_NON_RANDOM_WORDS 2>/dev/null | grep -v "'s")
    done
    lowercase=${word,,}
    echo "$lowercase"
}

function GetRandomURL {
    prefixList=("http://" "http://www." "www.")
    prefix=$(GetWordStringFromArr "${prefixList[@]}")
    domenList=(academy accountant accountants active actor adult aero agency airforce apartments app archi army associates asia attorney auction audio autos biz cat com coop dance edu eus family fun gov info int jobs mil mobi museum name net one ong onl online ooo org organic partners parts party pharmacy photo photography photos physio pics pictures feedback pink pizza place plumbing plus poker porn post press pro productions prof properties property qpon racing recipes red rehab ren rent rentals repair report republican rest review reviews rich site tel trade travel xxx xyz yoga zone ninja art moe dev)
    domen=$(GetWordStringFromArr "${domenList[@]}")
    
    echo "$prefix$(GetRandomWord).$domen"
}

# Агенты (Mozilla, Google Chrome, Opera, Safari, Internet Explorer, Microsoft Edge, Crawler and bot, Library and net tool)
    
    Agents=(
    "Mozilla/5.0 (Windows; U; Windows NT 6.1; rv:2.2) Gecko/20110201" 
    "Mozilla/5.0 (X11; U; Linux i686; pl-PL; rv:1.9.0.6) Gecko/2009020911" 
    "Mozilla/5.0 (Windows; U; Win98; en-US; rv:1.8a6) Gecko/20050111" 
    "Mozilla/5.0 (Windows; U; Windows NT 5.0; en-US; rv:1.4.1) Gecko/20031008"
    "Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.2.1) Gecko/20030409 Debian/1.2.1-9woody2"

    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.77 Safari/537.36"
    "Mozilla/5.0 (X11; Ubuntu; Linux i686 on x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/53.0.2820.59 Safari/537.36"
    "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_7_2) AppleWebKit/535.19 (KHTML, like Gecko) Chrome/18.0.1025.45 Safari/535.19"
    "Chrome/15.0.860.0 (Windows; U; Windows NT 6.0; en-US) AppleWebKit/533.20.25 (KHTML, like Gecko) Version/15.0.860.0"
    "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_6_6) AppleWebKit/534.24 (KHTML, like Gecko) Chrome/11.0.698.0 Safari/534.24"

    "Opera/9.80 (X11; Linux i686; Ubuntu/14.10) Presto/2.12.388 Version/12.16.2"
    "Opera/9.80 (Windows NT 5.1; U; it) Presto/2.7.62 Version/11.00"
    "Mozilla/5.0 (Windows NT 5.1; U; Firefox/5.0; en; rv:1.9.1.6) Gecko/20091201 Firefox/3.5.6 Opera 10.53"
    "Opera/9.60 (Windows NT 6.0; U; ru) Presto/2.1.1"
    "Mozilla/5.0 (X11; Linux x86_64; U; en; rv:1.8.1) Gecko/20061208 Firefox/2.0.0 Opera 9.60"
    
    "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_7_3) AppleWebKit/534.55.3 (KHTML, like Gecko) Version/5.1.3 Safari/534.53.10"
    "Mozilla/5.0 (Macintosh; U; Intel Mac OS X 10_6_6; de-de) AppleWebKit/533.20.25 (KHTML, like Gecko) Version/5.0.4 Safari/533.20.27"
    "Mozilla/5.0 (iPhone; U; CPU iPhone OS 4_3 like Mac OS X; fr-fr) AppleWebKit/533.17.9 (KHTML, like Gecko) Version/5.0.2 Mobile/8F190 Safari/6533.18.5"
    "Mozilla/5.0 (Macintosh; U; Intel Mac OS X 10_6_2; ru-ru) AppleWebKit/533.2+ (KHTML, like Gecko) Version/4.0.4 Safari/531.21.10"
    "Mozilla/5.0 (Macintosh; U; PPC Mac OS X; fr) AppleWebKit/417.9 (KHTML, like Gecko)"
    
    "Mozilla/5.0 (compatible, MSIE 11, Windows NT 6.3; Trident/7.0; rv:11.0) like Gecko"
    "Mozilla/5.0 (compatible; MSIE 10.6; Windows NT 6.1; Trident/5.0; InfoPath.2; SLCC1; .NET CLR 3.0.4506.2152; .NET CLR 3.5.30729; .NET CLR 2.0.50727) 3gpp-gba UNTRUSTED/1.0"
    "Mozilla/5.0 (compatible; MSIE 10.0; Windows NT 7.0; InfoPath.3; .NET CLR 3.1.40767; Trident/6.0; en-IN)"
    "Mozilla/5.0 (Windows; U; MSIE 9.0; WIndows NT 9.0; en-US))"
    "Mozilla/5.0 (compatible; MSIE 8.0; Windows NT 5.1; Trident/4.0; .NET CLR 1.1.4322; .NET CLR 2.0.50727)"

    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.102 Safari/537.36 Edge/18.19582"
    "Chrome (AppleWebKit/537.1; Chrome50.0; Windows NT 6.3) AppleWebKit/537.36 (KHTML like Gecko) Chrome/51.0.2704.79 Safari/537.36 Edge/14.14393"
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML like Gecko) Chrome/46.0.2486.0 Safari/537.36 Edge/13.10586"
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/42.0.2311.135 Safari/537.36 Edge/12.246"
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.102 Safari/537.36 Edge/18.19577"

    "Mozilla/5.0 (compatible; mxbot/1.0; +http://www.chainn.com/mxbot.html)"
    "radian6_default_(www.radian6.com/crawler)"
    "Sosospider+(+http://help.soso.com/webspider.htm)"
    "VORTEX/1.2 ( http://marty.anstey.ca/robots/vortex/)"
    "Mozilla/5.0 (compatible; YodaoBot/1.0; http://www.yodao.com/help/webmaster/spider/; )"

    "curl/7.21.0 (x86_64-pc-linux-gnu) libcurl/7.21.0 OpenSSL/0.9.8o zlib/1.2.3.4 libidn/1.18 libssh2/1.2.5"
    "curl/7.21.0 (x86_64-pc-linux-gnu) libcurl/7.21.0 OpenSSL/0.9.8o zlib/1.2.3.4 libidn/1.15 libssh2/1.2.5"
    "curl/7.18.0 (x86_64-pc-linux-gnu) libcurl/7.18.0 OpenSSL/0.9.8g zlib/1.2.3.3 libidn/1.1"
    "curl/7.15.1 (x86_64-suse-linux) libcurl/7.15.1 OpenSSL/0.9.8a zlib/1.2.3 libidn/0.6.0"
    "curl/7.11.1 (i386-redhat-linux-gnu) libcurl/7.11.1 OpenSSL/0.9.7a ipv6 zlib/1.2.1.2"

    "PHP/5.2.9"
    "PycURL/7.23.1"
    "Python-urllib/3.1"
    "AppEngine-Google; (+http://code.google.com/appengine; appid: unblock4myspace)"
    "MetaURI API/2.0 metauri.com"
    )

# 127.0.0.1 - - [10/Oct/2020:15:10:20 -0600] "HEAD / HTTP/1.1" 200 0 "<https://example.com>" "Mozilla/5.0..."

function GetLogRow {
    count=0
    rowsNumber=`shuf -i 100-1000 -n 1`
    while [ $count -lt $rowsNumber ]
    do
        q='"'
        IP=`GetRandomIp`
        current_date=$1
        conact_1=" - - ["
        concat_2=":$(GetRandomTime) +0000] "
        date_concat=$conact_1$current_date$concat_2
        HTTPMetod='"'`GetWordStringFromArr "${RandomHTTPMetodArr[@]}"`
        resourceName=`GetRandomWord`
        ext=`GetWordStringFromArr "${RandomExtArr[@]}"`
        protocol=" /$resourceName.$ext HTTP/1.1$q"
        status=`GetWordStringFromArr "${ResponseCodes[@]}"`
        body_bytes_sent=$((RANDOM%8096))
        http_user_agent="`GetStringStringFromArr "Agents[@]"`"
        http_referer="`GetRandomURL`"
        final_url="$IP$conact_1$current_date$concat_2 $HTTPMetod$URLS$protocol $status $body_bytes_sent $q$http_referer$q $q$http_user_agent$q"
        echo $final_url
        let count++
    done
}

function MakeLogFiles {
    i=1
    while [[ $i -le 5 ]];
    do
        newDate="`GetNextDate`"
        filename="${newDate//'/'/'_'}"
        sudo bash -c "touch $filename.log && chmod +777 $filename.log"
        GetLogRow $newDate | sort -k4 >> $filename.log #time sort
        let i++
    done
}

MakeLogFiles