/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    var list = s.split(" ").filter((i)=> i.length > 0);
    list.reverse()
    var ans = "";
    for(let i=0; i<list.length; i++){
        if(i > 0 && i < list.length) ans += " ";
        ans += list[i];
    }
    return ans;
};