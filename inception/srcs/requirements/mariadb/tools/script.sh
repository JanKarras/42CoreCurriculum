#!/bin/bash
set -e

INIT_FILE="/var/lib/mysql/.init_done"

echo "[1] 🟢 Starte MariaDB im Hintergrund mit mysqld_safe..."
mysqld_safe &

echo "[2] ⏳ Warte auf MySQL-Server, maximal 30 Sekunden..."
for i in {30..0}; do
    if mysqladmin ping --silent; then
        echo "[2] ✅ MySQL antwortet."
        break
    fi
    echo "[2] ...noch nicht bereit ($i)"
    sleep 1
done

if [ "$i" = 0 ]; then
    echo "[2] ❌ MySQL startete nicht rechtzeitig. Abbruch."
    exit 1
fi

if [ ! -f "$INIT_FILE" ]; then
    echo "[3] 🛠️ Führe Initial-SQL-Konfiguration aus..."

    mysql -uroot <<EOSQL
CREATE DATABASE IF NOT EXISTS $db1_name;
CREATE USER IF NOT EXISTS '$db1_user'@'%' IDENTIFIED BY '$db1_pwd';
GRANT ALL PRIVILEGES ON $db1_name.* TO '$db1_user'@'%';
ALTER USER 'root'@'localhost' IDENTIFIED BY '$db_root_pwd';
FLUSH PRIVILEGES;
EOSQL

    touch "$INIT_FILE"
    echo "[3] ✅ Initialisierung abgeschlossen und Marker-Datei geschrieben."
else
    echo "[3] 🔁 MariaDB wurde bereits initialisiert – überspringe Setup."
fi

echo "[4] 📌 MariaDB läuft jetzt im Vordergrund (Docker benötigt das)..."
wait
