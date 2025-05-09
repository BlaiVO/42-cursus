--ALTER USER 'root@localhost' IDENTIFIED BY '{SQL_ROOT_PASSWORD}';

CREATE DATABASE IF NOT EXISTS {SQL_DB};

CREATE USER IF NOT EXISTS '{SQL_USER}' IDENTIFIED BY '{SQL_PASSWORD}';

GRANT ALL PRIVILEGES ON {SQL_DB}.* TO '{SQL_USER}'@'%';

FLUSH PRIVILEGES;