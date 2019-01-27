process.stdin.resume();
process.stdin.setEncoding("utf-8");
var stdin_input = "";

process.stdin.on("data", function (input) {
    stdin_input += input;                               // Reading input from STDIN
});

process.stdin.on("end", function () {
    main(stdin_input);
});

function main(input) {
    var lines = input.split('\n'), lineCnt = -1;
    var getNextLine = function () {
        return lines[++lineCnt];
    };
    var getArrFromLine = function (line) {
        return line.split(' ').map(function (e) {
            return parseInt(e, 10);
        });
    };

    var q = parseInt(getNextLine(), 10);
    while (q-- > 0) {
        var n = parseInt(getNextLine(), 10);
        var u = getArrFromLine(getNextLine());
        var a = getArrFromLine(getNextLine());

        var ans = 0;
        for (var j = 0; j < n;) {
            var k, max = a[j];
            for (k = j + 1; k < n; k++) {
                if (u[k] === u[j])
                    max = Math.max(max, a[k]);
                else
                    break;
            }
            ans += max;
            j = k;
        }
        console.log(ans);
    }
}
