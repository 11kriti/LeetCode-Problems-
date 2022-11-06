/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var orderlyQueue = function(s, k) {
    
 	let res = s;

	if (k === 1) {
		let l = s.length;
		for (let i=0; i<l; i++) {
			let c = s[0];
			s = s.substring(1, l) + c;
			if (s < res)
				res = s; 
		}

		return res;
	}

	return [...s].sort().join('');
   
};
