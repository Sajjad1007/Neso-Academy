package neso;

public class BitwiseShiftOperators {

    public static void main(String[] args) {
        var positiveNum = 15;
        var negativeNum = -15;
        System.out.println("\nEach value of these expression is automatically promoted to integer.");
        System.out.println("Here left/right/unsigned shifting is happening in 2's complement form.");

        //Left shift operator
        System.out.println();
        System.out.println("Leftmost bit(sign bit) remains same. Rightmost bit is always filled by 0.");
        System.out.format(" 15 << 1 = " + "%3d", (positiveNum << 1));
        System.out.println(",           0000000000000000000000000000" + Integer.toBinaryString(positiveNum) + "  << 1 = " + "000000000000000000000000000" + Integer.toBinaryString(positiveNum << 1));
        System.out.format("-15 << 1 = " + "%3d", (negativeNum << 1));
        System.out.println(",           " + Integer.toBinaryString(negativeNum) + "  << 1 = " + Integer.toBinaryString(negativeNum << 1));

        //Right shift operator
        System.out.println();
        System.out.println("Leftmost bit is filled by the sign bit.");
        System.out.format(" 15 >> 1 = " + "%3d", (positiveNum >> 1));
        System.out.println(",           0000000000000000000000000000" + Integer.toBinaryString(positiveNum) + "  >> 1 = " + "00000000000000000000000000000" + Integer.toBinaryString(positiveNum >> 1));
        System.out.format("-15 >> 1 = " + "%3d", (negativeNum >> 1));
        System.out.println(",           " + Integer.toBinaryString(negativeNum) + "  >> 1 = " + Integer.toBinaryString(negativeNum >> 1));

        //Unsigned right shift operator
        System.out.println();
        System.out.println("Leftmost bit is always filled by 0.");
        System.out.format(" 15 >>> 1 = " + "%2d", (positiveNum >>> 1));
        System.out.println(",           0000000000000000000000000000" + Integer.toBinaryString(positiveNum) + " >>> 1 = " + "00000000000000000000000000000" + Integer.toBinaryString(positiveNum >>> 1));
        System.out.print("-15 >>> 1 = " + (negativeNum >>> 1));
        System.out.println(",   " + Integer.toBinaryString(negativeNum) + " >>> 1 = 0" + Integer.toBinaryString(negativeNum >>> 1));
        System.out.println("\nAlhamdulillah now it's all clear.");
    }

}