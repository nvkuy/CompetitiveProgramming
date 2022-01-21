#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, a, vc, va, c, b, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> a >> va;
        cin >> c >> vc;
        cin >> b;
        if (vc - va == c - a)
            cout << vc - c + b;
        else
            cout << min(va + b - a, vc);
        cout << endl;
    }

    return 0;
}
/*
import kotlin.math.min
import java.util.Scanner

fun main(args : Array<String>) {
    val reader = Scanner(System.`in`)
    var t:Int = reader.nextInt()
    while (t > 0) {
        t--
        var n:Int = reader.nextInt()
        var a:Int = reader.nextInt()
        var va:Int = reader.nextInt()
        var c:Int = reader.nextInt()
        var vc:Int = reader.nextInt()
        var b:Int = reader.nextInt()
        if (vc - va == c - a)
            println(vc - c + b)
        else
            println(min(va + b - a, vc))
    }
}
*/
