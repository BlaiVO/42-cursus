#!/bin/bash

sleep 5

if [ ! -d /var/lib/mysql/${SQL_DB} ] ; 
then
	mysql_install_db --user=mysql --ldata=/var/lib/mysql

	# mysql_safe --datadir='/var/lib/mysql' &

    sed -e "s|{SQL_ROOT_PASSWORD}|${SQL_ROOT_PASSWORD}|g" \
        -e "s|{SQL_DB}|${SQL_DB}|g" \
        -e "s|{SQL_USER}|${SQL_USER}|g" \
        -e "s|{SQL_PASSWORD}|${SQL_PASSWORD}|g" \
        /usr/local/bin/.db_init.sql > /usr/local/bin/db_init.sql
    
    service mariadb start
	sleep 5

    /usr/bin/mysql -u ${SQL_ROOT_USER} -p${SQL_ROOT_PASSWORD} < /usr/local/bin/db_init.sql
    mysqladmin -u ${SQL_ROOT_USER} --password=${SQL_ROOT_PASSWORD} shutdown
fi

exec "$@"

# mysql -u ${SQL_ROOT_USER} -p $(SQL_ROOT_PASSWORD) < /usr/local/bin/db_init.sql
