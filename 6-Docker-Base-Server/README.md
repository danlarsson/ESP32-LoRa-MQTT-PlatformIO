# 6 - Docker 

Sjätte delen av kursen, här tittar vi på att sätta upp en server för att kunna ta emot meddelanden, lösningen bygger på docker och installerar ett flertal olika komponenter.

## Docker
https://www.docker.com/
Är ett verktyg för att viritualisera applikationer i stället för hela servrar. Så i stället för att installera till exempel en hel Linuxinstalation så installerar Docker en mycket mindre del av bara den applikation man vill ha.

Docker kan installeras på alla "vanliga" operativsystem. Vi kommer att använda Raspian från RaspberryPi. Jag har testat på MacOS utan problem, på Windows är det en rätt komplicerad installation som jag inte kan rekommendera. Det skall även gå att installera Docker/Docker-compose på Synology om man har en lite nyare enhet.

Efter installtion av Docker så skapa en katalog där du vill ha installationen. Lägg docker-compose.yaml filen och mqtt katalogen med innehåll i katalogen.
docker-compose.yml filen innehåller inställningar och de applikationer som vi kommer att använda.

Öppna en komandorompt "Svart läskigt fönster", ställ dig i katalogen du skapat och skriv 'docker-compose up' för att ladda hem alla images och starta tjänsterna. Lägg till '-d' för att starta den som en demon i bakgrunden.

För att stänga ner alla tjänster 'docker-compose down' eller en specifik tjänst 'docker-compose down mqtt'

## MQTT
Är själva hjärtat i lösningen, en Message Broaker. Tanken är att all trafik skall passera MQTT för att sen kunna skickas vidare.
För att MQTT skall fungera så behövs en configurationsfil, den  finns med i mqtt-katalogen här.

## InfluxDB
http://localhost:8086
Är en tidsseriedatabas, en databas som sparar information baserat på tid. Passar väldigt bra för att lagra till exempel ett temperaturvärde.

## NodeRed
http://localhost:1880
Är ett väldigt kraftfullt verktyg för att koppla ihop olika delar. Den kan till exempel lyssna på ett MQTT-meddelande och skicka det vidare till InfluxDB
NodeRed har även funktioner för att bygga dashboards och mycket mer.

## Grafana
http://localhost:3000
Är ett verktyg för att visa grafer av olika de sorter och modeller. Kan hämta information från till exempel InfluxDB och bygga en graf. Har många olika plugins och funktioner.
