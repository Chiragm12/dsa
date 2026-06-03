class PC {
    String cpu;
    String ram;
    String storage;
    String gpu;
    double price;

    void showConfig() {
        System.out.println(cpu + ", " + ram + ", " + storage + ", " + gpu);
        System.out.println("Price: " + price);
    }
}

class PricingEngine {
    private static PricingEngine instance;

    private PricingEngine() {}

    public static PricingEngine getInstance() {
        if (instance == null)
            instance = new PricingEngine();
        return instance;
    }

    public double calculatePrice(PC pc) {
        double price = 0;
        if (pc.cpu != null) price += 200;
        if (pc.ram != null) price += 100;
        if (pc.storage != null) price += 150;
        if (pc.gpu != null) price += 300;
        return price;
    }
}

abstract class PCBuilder {
    protected PC pc = new PC();

    abstract void buildCPU();
    abstract void buildRAM();
    abstract void buildStorage();
    abstract void buildGPU();

    public PC getPC() {
        pc.price = PricingEngine.getInstance().calculatePrice(pc);
        return pc;
    }
}

class GamingPCBuilder extends PCBuilder {
    void buildCPU() { pc.cpu = "High-end CPU"; }
    void buildRAM() { pc.ram = "16GB"; }
    void buildStorage() { pc.storage = "1TB SSD"; }
    void buildGPU() { pc.gpu = "RTX GPU"; }
}

class OfficePCBuilder extends PCBuilder {
    void buildCPU() { pc.cpu = "Mid-range CPU"; }
    void buildRAM() { pc.ram = "8GB"; }
    void buildStorage() { pc.storage = "512GB SSD"; }
    void buildGPU() { pc.gpu = null; }
}

class PCDirector {
    void constructPC(PCBuilder builder) {
        builder.buildCPU();
        builder.buildRAM();
        builder.buildStorage();
        builder.buildGPU();
    }
}

public class Main2 {
    public static void main(String[] args) {
        PCDirector director = new PCDirector();

        PCBuilder gaming = new GamingPCBuilder();
        director.constructPC(gaming);
        gaming.getPC().showConfig();

        PCBuilder office = new OfficePCBuilder();
        director.constructPC(office);
        office.getPC().showConfig();
    }
}