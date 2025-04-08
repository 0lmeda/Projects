
string encrypt(const string pass, const string key){
	string result = pass;
	for(size_t i = 0; i<pass.size(); i++){
	result[i] = pass[i] ^ key[i % key.size()];
	}
	return result;
}
