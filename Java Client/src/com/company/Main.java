package com.company;
import java.io.*;
import java.net.*;
import java.sql.SQLOutput;
import java.util.Scanner;

public class Main {


    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        try {
            Socket sock = new Socket("127.0.0.1", 4977);
            boolean loop = true;

            InputStream in=null;
            PrintWriter out = null;

            while (loop) {

                System.out.println("1. getSensortypes()#");
                System.out.println("2. Sensor(air)#");
                System.out.println("3. Sensor(noise)#");
                System.out.println("4. Sensor(light)#");
                System.out.println("5. getAllSensors()#");
                System.out.println("6. close");


                int command = input.nextInt();
                String msg = "default";

                out = new PrintWriter(sock.getOutputStream(), true);


                switch (command) {
                    case 1:
                      //  msg = "getSensortypes()";
                        out.println("getSensortypes()");
                        break;
                    case 2:
                     //   msg = "Sensor(air)";
                        out.println("Sensor(air)");
                        break;
                    case 3:
                     //   msg = "Sensor(noise)";
                        out.println("Sensor(noise)");
                        break;
                    case 4:
                      //  msg = "Sensor(light)";
                        out.println("Sensor(light)");
                        break;
                    case 5:
                     //   msg = "getAllSensors()";
                        out.println("getAllSensors()");
                        break;
                    case 6:
                      //  msg = "close";
                        out.println("close");
                        sock.close();
                        loop = false;
                        break;
                    default:
                        System.out.println("choose a valid command");
                        break;
                }



                //  BufferedReader in = new BufferedReader(new InputStreamReader(sock.getInputStream()));
                in = sock.getInputStream();

                int data = -1;
                StringBuffer line = new StringBuffer();
                String str="";
                while ((data = in.read()) != -1) {

                    line.append((char) data);
                    System.out.println((char) data);


                  if (((char) data) == '#') {
                        break;
                    }


                }

                    System.out.println(line);




            }

            out.flush();
            out.close();
            in.close();
            sock.close();

        } catch(SocketException s){
            System.out.print("connection closed");

        } catch (IOException e) {

            e.printStackTrace();

        }
    }
}
