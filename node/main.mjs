import readline from "readline";

const inout = readline.createInterface(process.stdin, process.stdout);

inout.on('line', (line) => {
  console.log(line);
})