//https://leetcode.com/discuss/interview-question/373006
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, list<string> > favoritegenre(
    unordered_map<string, list<string> > userMap, unordered_map<string, list<string> > genreMap) {
	unordered_map<string, list<string> > result;
	unordered_map<string, string> songsGenres;

	for (auto x : genreMap) {
		for (auto song : genreMap[x.first]) {
			songsGenres[song] = x.first;
		}
	}

	for (auto x : userMap) {
		unordered_map<string, int> temp;
		pair<int, list<string> > maximum = {0, {}};
		for (auto song : userMap[x.first]) {
			if (!songsGenres.count(song)) {
				continue;
			}
			temp[songsGenres[song]]++;
			if (temp[songsGenres[song]] == maximum.first) {
				maximum.second.push_back(songsGenres[song]);
			}
			if (temp[songsGenres[song]] > maximum.first) {
				maximum = {temp[songsGenres[song]], {songsGenres[song]}};
			}
		}
		result[x.first] = maximum.second;
	}

	return result;
}

int main(int argc, char const *argv[])
{
	unordered_map<string, list<string> > userSongs;
	unordered_map<string, list<string> > songGenres;

	userSongs["David"] = {"song1", "song2"};
	userSongs["Emma"] = { "song3", "song4"};

	unordered_map<string, list<string> > result = favoritegenre(userSongs, songGenres);
	for (auto x : result) {
		cout << x.first << ": ";
		for (auto song : result[x.first]) {
			cout << song << ", ";
		} cout << endl;
	}


	return 0;
}

// Input
// userSongs = {
// "David": ["song1", "song2", "song3", "song4", "song8"],
// "Emma":  ["song5", "song6", "song7"]
// },
// songGenres = {
// "Rock":    ["song1", "song3"],
// "Dubstep": ["song7"],
// "Techno":  ["song2", "song4"],
// "Pop":     ["song5", "song6"],
// "Jazz":    ["song8", "song9"]
// }

// Output: {
// "David": ["Rock", "Techno"],
// "Emma":  ["Pop"]
// }

// userSongs["David"] = {"song1", "song2", "song3", "song4", "song8"};
// userSongs["Emma"] = {"song5", "song6", "song7"};

// songGenres["Rock"] = {"song1", "song3"};
// songGenres["Dubstep"] = {"song7"};
// songGenres["Techno"] = {"song2", "song4"};
// songGenres["Pop"] = {"song5", "song6"};
// songGenres["Jazz"] = {"song8", "song9"};




// Input:
// userSongs = {
//    "David": ["song1", "song2"],
//    "Emma":  ["song3", "song4"]
// },
// songGenres = {}

// Output: {
//    "David": [],
//    "Emma":  []
// }



