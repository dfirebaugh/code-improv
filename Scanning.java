// Scanning Code
public class Scanning extends Thread {

	int n=1;
	float max= 50;
	public static void main(String...args){
		Scanning s = new Scanning();
		s.start();
	}

	public void run(){
		try{
			while(n<=max){
				System.out.print("[");
					for(float i =1;i<=n;i++){
						System.out.print("#");
					}
					for (float i =n+1;i<=max;i++){
						System.out.print("_");
					}
				System.out.print("]");
				System.out.print(" "+ n*2 + "% " +"\r");
				n++;
				Thread.sleep(500);

			}
		System.out.println("Scanning Completed !");

		}
			catch(Exception e){
				
			}
		}
	}
