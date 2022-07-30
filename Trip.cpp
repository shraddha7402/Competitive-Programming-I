import java.util.Scanner;
public class TheTrip {
public static void main(String[] args) {
// TODO code application logic here
Scanner scan = new Scanner(System.in);
double negDiff, posDiff, minDiff, avg, total =0.0;
double money[] = new double[1000];
int n = scan.nextInt();
for(int i = 0; i < n ; i++){
money[i] = scan.nextDouble();
total += money[i];
}
avg = (long) ((total / n) * 100.0) / 100.0;
negDiff = 0.0;
posDiff = 0.0;
for(int i = 0; i < n ; i++){
if(money[i] > avg){
posDiff += (long) ( (money[i] - avg) * 100.0) /100.0;
}else{
negDiff += (long) ( (avg - money[i]) * 100.0) /100.0;
}
}
minDiff = posDiff > negDiff ? negDiff : posDiff;
System.out.println(minDiff);
}
}