public class CpuInfo
{
	public static void main(String[] args)
	{
		
		
		String nameOS = "os.name";
	String versionOS = "os.version";
	String architectureOs="os.arch";
	
	System.out.println("\n The information about processor \n no. of CPU in the System are:-");
	
	System.out.println("Available processors (cores): " + 
		        Runtime.getRuntime().availableProcessors());
	
	System.out.println(System.getenv("NUMBER_OF_PROCESSORS"));
	System.out.println("\n Processor Manufacturer");
	System.out.println(System.getenv("PROCESSOR_IDENTIFIER"));
	System.out.println("\n \n the Information about OS");
	System.out.println("\n Name of the OS:-"+System.getProperty(nameOS));
	System.out.println("\n VERSION of the OS:-"+System.getProperty(versionOS));
	System.out.println("\n Architecture of the OS:-"+System.getProperty(architectureOs));
	}
}
