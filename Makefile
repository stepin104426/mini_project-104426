SRC = src/104426code.c src/readstruc.c 


INC = -Iinc

PROJECT_NAME = trainsys.out

$(PROJECT_NAME): $(SRC)
	gcc $(SRC) $(INC) -o $(PROJECT_NAME)

run :$(PROJECT_NAME)
		./${PROJECT_NAME}

clean: 
		rm -rf $(PROJECT_NAME) documentation/html 