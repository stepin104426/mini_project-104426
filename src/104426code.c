#include "transys.h"

int main(){
	//tl_num;

	printf("\n -------- WELOCME TO TRAIN INFORMATION SYSTEM ---------\n\n      SELECT ANY OF THE BELOW MENU FOR FURTHER INFORMATION        \n");
	

	getTrainData();
	for (int k=0; k<train_count; k++) {
        	t_array[k]= &train_data[k];
        }
    show_menu();    

	return 0;
}



void show_menu(){
	char num ,menu_num, back, option;
	
	do{
	printf ("\n 1. INTERACTIVE MENU            2.TRAIN LISTING               3. TRAIN SEARCH       E TO EXIT\n");
	scanf(" %c", &menu_num);

	switch(menu_num){
			case '1':printf("\n INTERACTIVE MENU \n");
					 printf("\n ALL TRAINS \n\n");

					 train_sort(1);

					 printf("\n PRESS Y to see the same menu.\n PRESS E to see the EXIT\n");
					 scanf(" %c", &option);
					 
					 break;
			case '2':option = train_listing();
					 
					 break;
			case '3':printf("\n\n 1.Train Name\n 2.Timings\n 3.Source/destination\n\n"); 
					 option = train_search();
					break;
			default: 
					  option = 'E'; 
					break;

	}
} while (option != 'E');
	
	printf("\n EXITING..");
	
}

char train_listing(){
	char num2, back;

	do{
	printf("\n 1. ALPHABETICAL\n 2. TIMINGS\n 3. FROM SOURCE \n 4.TO DESTINATION \n");
	printf("\n Select the choice:");
	scanf(" %c", &num2);

		switch(num2){

			case '1': printf( "\nALPHABETICAL\n\n");

					  train_sort(1);

                      printf("\n PRESS Y to see the same menu.\n PRESS N to see the MAIN menu \n");
					  scanf(" %c", &back);
					break;
			case '2': printf( "\n TIMINGS \n\n");
					  //printf("entered\n");
					  train_sort(4);

					  printf("\n PRESS Y to see the same menu.\n PRESS N to see the MAIN menu \n");
					  scanf(" %c", &back);
					break;
			case '3': printf( "\n FROM SOURCE \n");

					  train_sort(2);

					  printf("\n PRESS Y to see the same menu.\n PRESS N to see the MAIN menu \n");
					  scanf(" %c", &back);
					break;
			case '4': printf( "\n TO DESTINATION \n");

					  train_sort(3);
					  
					  printf("\n PRESS Y to see the same menu.\n PRESS N to see the MAIN menu \n");
					  scanf(" %c", &back);
					break;
			case '5': printf("\n PRESS N to see the MAIN menu \n");
					  scanf(" %c", &back);
			 					
		}
	} while (back!= 'N');

	return 'M';	 
}


char train_search(){
	char num3, back ;

	do{
	printf("Select the choice:");
	scanf(" %c", &num3);

		switch(num3){
			case '1': printf( "\n TRAIN NAME \n");
					  printf("\n PRESS Y to see the same menu.\n PRESS N to see the MAIN menu \n");
					  scanf(" %c", &back);
					break;
			case '2': printf( "TIMINGS \n");
					  printf("\n PRESS Y to see the same menu.\n PRESS N to see the MAIN menu \n");
					  scanf(" %c", &back);
					break;
			case '3': printf( "\n SOURCE & DESTINATION: Enter the source and destination \n");
					  printf("\n PRESS Y to see the same menu.\n PRESS N to see the MAIN menu \n");
					  scanf(" %c", &back);
					break;
			case '4': printf("\n PRESS N to see the MAIN menu \n");
					  scanf(" %c", &back);
			//default: 
					  			
		}

	} while (back != 'N');

	return 'M';	
}


void train_sort(int sort_type){
	printf("entered\n");

	int i, j;
  	train *temp;

	for(i = 0; i < train_count; ++i) {
    	for(j = i + 1; j < train_count; j++) {
        	if(compare_train(t_array[i], t_array[j], sort_type) > 0) {
            	temp = t_array[i];
            	t_array[i]=t_array[j];
            	t_array[j]=temp;
        	}    	
    	}
	}

	for (int k=0; k<train_count; k++) {

       printf("%d     ",train_data[k].sl_no);
       printf("%s     ",t_array[k]->train_name);
       printf("%d     ",t_array[k]->train_number);
       printf("%s     ",t_array[k]->source);
       printf("%s     ",t_array[k]->destination);
       printf("%s     ",t_array[k]->arr_time);
       printf("%s     ",t_array[k]->dept_time);
       printf("\n\n");
    }

}


int compare_train(train *t_array1,train *t_array2, int num){

	int ret=0;
	switch(num){

		case 1 : ret = strcmp(t_array1->train_name, t_array2->train_name);
				 break; 
		case 2 : ret = strcmp(t_array1->source, t_array2->source);
				 break; 
		case 3 : ret = strcmp(t_array1->destination, t_array2->destination);
				 break; 
		case 4 : ret = compare_time(t_array1->arr_time, t_array2->arr_time);
	}

	return ret;
	
}


int compare_time(char* t1, char* t2){

	char temp1[4];
	char temp2[4];
	int T1,T2;

	temp1[0]= t1[0];
	temp1[1]= t1[1];
	temp1[2]= t1[3];
	temp1[3]= t1[4];

	temp2[0]= t2[0];
	temp2[1]= t2[1];
	temp2[2]= t2[3];
	temp2[3]= t2[4];

	T1 = atoi(temp1);
	T2 = atoi(temp2);

	if(T1> T2){
		return 1;
	} else{
		return 0;
	}


}



