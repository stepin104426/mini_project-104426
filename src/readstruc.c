#include "transys.h"

void getTrainData(){

	FILE * filehandle;
        char lyne[121];

      char *item;
      train_count = 0;
        int k;

	filehandle = fopen("data/information.txt","r");

	while (fgets(lyne,120,filehandle)) {
                //printf("%s\n",lyne);

                item = strtok(lyne,",");
                train_data[train_count].sl_no = atof(item);

                item = strtok(NULL,",");
                train_data[train_count].train_number = atof(item);

                item = strtok(NULL,",");
                strcpy(train_data[train_count].train_name,item);

                item = strtok(NULL,",");
                strcpy(train_data[train_count].source,item);

                item = strtok(NULL,",");
                //printf("%s\n",item);
                strcpy(train_data[train_count].destination, item);

                item = strtok(NULL,",");
                strcpy(train_data[train_count].arr_time,item);

                item = strtok(NULL,",");
                strcpy(train_data[train_count].dept_time,item);

                train_count++;
                }


                

        fclose(filehandle);

       
}
        