


#include <stdio.h>

int is_Capital(char ch) {
    return (ch >= 'A' && ch <= 'Z');
}

int main() {
    char c;
    printf("Enter a character: ");
    scanf(" %c", &c);

    if (is_Capital(c))
        printf("'%c' is a Capital letter.\n", c);
    else
        printf("'%c' is NOT a Capital letter.\n", c);

    return 0;
}









//#include <stdio.h>

//int Sum_even(int M,int N){
//   
//       printf ("%d",M + N) ;
//    }
//
//int main() {
//	
//    int num1,num2;
//    printf("Enter the first number: ");
//    scanf("%d",&num1);
//    printf("Enter the second number: ");
//    scanf("%d",&num2);
//     if(num1 % 2 ==0 && num2 %2 ==0){
//         Sum_even(num1,num2);
//     }else{
//         printf("Enter the Even numbers");
//     }
//
//    return 0;
//}



//#include <stdio.h>
//int sumMSD_LSD(int num){
//	int lsd = num % 10;
//	int msd = num / 100;
//	
//	return msd + lsd ;
//}
//int main(){
//	int num;
//	printf("Enter a 3 digit num ");
//	scanf("%d",&num);
//	if(num >=100 && num<=999){
//	 printf("Sum of MSD and LSD = %d\n", sumMSD_LSD(num));
//	}else{
//		printf("Invalid Input!!");
//	}
//}








