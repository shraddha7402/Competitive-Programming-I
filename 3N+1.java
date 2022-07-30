import java.util.Scanner;
public class ThrreeMaxCycle {
public static void main(String[] args) {
// TODO code application logic here
Scanner scan = new Scanner(System.in);
int i = scan.nextInt();
int j = scan.nextInt();
scan.close(); 
int temp, cycle_length, max = 0;
for(int k = i; k <= j; k++){
temp = k;
cycle_length = 1; 
while(temp > 1 && temp < 1000000){
if( temp %2 == 0){
temp = temp /2;
}else{
temp = (temp * 3) + 1;
}
cycle_length++;
}
if(cycle_length > max){
max = cycle_length;
}
 }
System.out.println(i + " " + j + " " + max);
 }
}