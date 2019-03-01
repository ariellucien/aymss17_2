import javax.swing.*;
import java.awt.*;

public class VentanaSimple extends JFrame
{
    public VentanaSimple()
    {
        setBounds(50,50, 500, 500);
        setVisible(true);

    }
    public static void main(String[]args)
    {
        VentanaSimple v = new VentanaSimple();
    }
}