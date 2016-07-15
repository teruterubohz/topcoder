// BEGIN CUT HERE

// END CUT HERE
using System;
using System.Text;
using System.Text.RegularExpressions;
using System.Collections;

public class BinaryCode {
    public string[] decode(string message) {
        string[] res = new string[2];
        int[] decodeInt = new int[message.Length+1];
        int[] encodeInt = new int[message.Length + 1];
        string str = null;

        decodeInt[0] = 0;
        for( int i = 0; i<message.Length;i++)
        {
            decodeInt[i + 1] = message[i] - '0';
        }

        encodeInt[0] = 0;
        encodeInt[1] = 0;
        for(int i = 1; i < message.Length; i++)
        {
            encodeInt[i + 1] = decodeInt[i] - encodeInt[i - 1] - encodeInt[i];
            if (encodeInt[i + 1] != 0 && encodeInt[i + 1] != 1)
            {
                res[0] = "NONE";
                break;
            }
        }

        if(res[0] != "NONE")
        {
            if (decodeInt[message.Length] != encodeInt[message.Length - 1] + encodeInt[message.Length]) 
                res[0] = "NONE";
            else
            {
                for(int i = 1; i<message.Length + 1;i++)
                    str += encodeInt[i].ToString();
                //Console.WriteLine(str);
                res[0] = str;
                str = null;
            }
        }

        encodeInt = new int[message.Length + 1];
        encodeInt[0] = 0;
        encodeInt[1] = 1;
        for (int i = 1; i < message.Length; i++)
        {
            encodeInt[i + 1] = decodeInt[i] - encodeInt[i - 1] - encodeInt[i];
            if (encodeInt[i + 1] != 0 && encodeInt[i + 1] != 1)
            {
                res[1] = "NONE";
                break;
            }
        }

        if (res[1] != "NONE")
        {
            if (decodeInt[message.Length] != encodeInt[message.Length - 1] + encodeInt[message.Length])
                res[1] = "NONE";
            else
            {
                for (int i = 1; i < message.Length + 1; i++)
                    str += encodeInt[i].ToString();
                res[1] = str;
                str = null;
            }
        }


        return res;
    }

// BEGIN CUT HERE
    public static void Main(String[] args) {
        try  {
            eq(0,(new BinaryCode()).decode("123210122"),new string[] { "011100011",  "NONE" });
            eq(1,(new BinaryCode()).decode("11"),new string[] { "01",  "10" });
            eq(2,(new BinaryCode()).decode("22111"),new string[] { "NONE",  "11001" });
            eq(3,(new BinaryCode()).decode("123210120"),new string[] { "NONE",  "NONE" });
            eq(4,(new BinaryCode()).decode("3"),new string[] { "NONE",  "NONE" });
            eq(5,(new BinaryCode()).decode("12221112222221112221111111112221111"),new string[] { "01101001101101001101001001001101001",  "10110010110110010110010010010110010" });
        } 
        catch( Exception exx)  {
            System.Console.WriteLine(exx);
            System.Console.WriteLine( exx.StackTrace);
        }
        System.Console.ReadKey();
    }
    private static void eq( int n, object have, object need) {
        if( eq( have, need ) ) {
            Console.WriteLine( "Case "+n+" passed." );
        } else {
            Console.Write( "Case "+n+" failed: expected " );
            print( need );
            Console.Write( ", received " );
            print( have );
            Console.WriteLine();
        }
    }
    private static void eq( int n, Array have, Array need) {
        if( have == null || have.Length != need.Length ) {
            Console.WriteLine("Case "+n+" failed: returned "+have.Length+" elements; expected "+need.Length+" elements.");
            print( have );
            print( need );
            return;
        }
        for( int i= 0; i < have.Length; i++ ) {
            if( ! eq( have.GetValue(i), need.GetValue(i) ) ) {
                Console.WriteLine( "Case "+n+" failed. Expected and returned array differ in position "+i );
                print( have );
                print( need );
                return;
            }
        }
        Console.WriteLine("Case "+n+" passed.");
    }
    private static bool eq( object a, object b ) {
        if ( a is double && b is double ) {
            return Math.Abs((double)a-(double)b) < 1E-9;
        } else {
            return a!=null && b!=null && a.Equals(b);
        }
    }
    private static void print( object a ) {
        if ( a is string ) {
            Console.Write("\"{0}\"", a);
        } else if ( a is long ) {
            Console.Write("{0}L", a);
        } else {
            Console.Write(a);
        }
    }
    private static void print( Array a ) {
        if ( a == null) {
            Console.WriteLine("<NULL>");
        }
        Console.Write('{');
        for ( int i= 0; i < a.Length; i++ ) {
            print( a.GetValue(i) );
            if( i != a.Length-1 ) {
                Console.Write(", ");
            }
        }
        Console.WriteLine( '}' );
    }
// END CUT HERE
}
