	import java.util.*;
	class MyClock{
		public static void main(String[] args){

			while(true){

				System.out.print(new Date()+"\r");
					try{
					Thread.sleep(1000);
				}
				catch(Exception e){
						System.out.println(e);
					}
			}
		}
	}