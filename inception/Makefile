all : up

up :
	@docker-compose -f ./srcs/docker-compose.yml up -d

down :
	@docker-compose -f ./srcs/docker-compose.yml down

stop :
	@docker-compose -f ./srcs/docker-compose.yml stop

start :
	@docker-compose -f ./srcs/docker-compose.yml start

status :
	@docker ps

clean :
	@docker-compose -f ./srcs/docker-compose.yml down
	@docker system prune -f

cleanall :
	@docker-compose -f ./srcs/docker-compose.yml down --rmi all -v
	@docker container prune -f
	@docker image prune -a -f
	@docker volume prune -f
	@sudo rm -rf /home/jkarras/data/mariadb
	@sudo rm -rf /home/jkarras/data/wordpress
	@sudo mkdir -p /home/jkarras/data/mariadb
	@sudo mkdir -p /home/jkarras/data/wordpress

