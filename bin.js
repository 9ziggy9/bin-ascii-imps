const b2String = (blob) => [...Array(blob.length / 8).keys()]
      .map(byteNo => blob.substring(8 * byteNo, 8 * (byteNo + 1)))
      .reduce((str, byte) => str + String.fromCharCode(parseInt(byte, 2)), "");

console.log(b2String("010000010100001001000011"));
