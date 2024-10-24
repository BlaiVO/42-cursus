FROM debian:bullseye

RUN apt-get update -y && \ 
	apt-get upgrade -y && \
	apt-get install mariadb-server -y && \
	rm -rf /var/lib/apt/lists/*

EXPOSE 3306

COPY ./conf/default.conf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY --chmod=755 ./tools/init.sh /usr/local/bin/db_init.sh
COPY --chmod=755 ./tools/init.sql /usr/local/bin/.db_init.sql

RUN mkdir -p /var/run/mysqld \
	&& chown -R mysql:mysql /var/run/mysqld

ENTRYPOINT ["/usr/local/bin/db_init.sh"]

CMD ["mysqld"]