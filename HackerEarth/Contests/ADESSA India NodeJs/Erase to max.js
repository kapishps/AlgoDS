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

    var t = parseInt(getNextLine(), 10);
    while (t-- > 0) {
        var n = parseInt(getNextLine(), 10);
        var a = getArrFromLine(getNextLine());

        var map = [];
        var ans = Infinity, sum = 0;
        for (var i = 0; i < n; i++) {
            sum += a[i];
            if (map[a[i]] !== undefined)
                map[a[i]]++;
            else
                map[a[i]] = 1;
        }

        for (var key in map) {
            ans = Math.min(ans, key * map[key]);
        }

        console.log(sum - ans);
    }
}
