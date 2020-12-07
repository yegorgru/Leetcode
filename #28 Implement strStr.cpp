#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <deque>

//Implement strStr()

//https://leetcode.com/problems/implement-strstr/

class Solution {
public:
	int RabinKarp(const std::string& text, const std::string& pattern) {
		int d = 10;
		if (pattern.size() == 0) {
			return 0;
		}
		else if (text.size() < pattern.size()) {
			return -1;
		}
		size_t j;
		int pattern_hash = 0;
		int text_hash = 0;
		int h = 1;
		for (size_t i = 0; i < pattern.size() - 1; i++) {
			h = (h * d) % (d + 3);
		}
		for (size_t i = 0; i < pattern.size(); i++) {
			pattern_hash = (d * pattern_hash + pattern[i]) % (d + 3);
			text_hash = (d * text_hash + text[i]) % (d + 3);
		}
		// Знаходимо співпадіння
		for (size_t i = 0; i <= text.size() - pattern.size(); i++) {
			if (pattern_hash == text_hash) {
				for (j = 0; j < pattern.size(); j++) {
					if (text[i + j] != pattern[j]) {
						break;
					}
				}
				if (j == pattern.size()) {
					return i;
				}
			}
			if (i < text.size() - pattern.size()) {
				text_hash = (d * (text_hash - text[i] * h) + text[i + pattern.size()]) % (d + 3);
				if (text_hash < 0) {
					text_hash = (text_hash + (d + 3));
				}
			}
		}
		return -1;
	}

	int naive(const std::string& text, const std::string& pattern)
	{
		if (pattern.size() == 0) {
			return 0;
		}
		else if (text.size() < pattern.size()) {
			return -1;
		}
		for (size_t i = 0; i <= text.size() - pattern.size(); i++) {
			size_t j;
			for (j = 0; j < pattern.size(); j++) {
				if (text[i + j] != pattern[j]) {
					break;
				}
			}
			if (j == pattern.size()) {
				return i;
			}
		}
		return -1;
	}

	bool HORSPOOL_check_loop(const std::string& text, const std::string& pattern, size_t& checked_end, size_t& pos,
		const std::map<char, size_t>& last) {
		for (;; pos--) {
			char checked = text[checked_end - (pattern.size() - 1) + pos];
			if (pattern[pos] != checked) {
				try {
					pos = last.at(text[checked_end]);
					checked_end += pattern.size() - 1 - pos;
					pos = pattern.size() - 1;
				}
				catch (const std::exception&) {
					pos = pattern.size() - 1;
					checked_end += pattern.size();
				}
				return false;
			}
			if (pos == 0) {
				return true;
			}
		}
	}

	int HORSPOOL(const std::string& text, const std::string& pattern)
	{
		if (pattern.size() == 0) {
			return 0;
		}
		else if (text.size() < pattern.size()) {
			return -1;
		}
		std::map<char, size_t>last;
		for (size_t i = 0; i < pattern.size() - 1; i++) {
			last[pattern[i]] = i;
		}
		size_t checked_end = pattern.size() - 1;
		size_t pos = checked_end;
		while (checked_end < text.size()) {
			if (HORSPOOL_check_loop(text, pattern, checked_end, pos, last)) {
				return checked_end + 1 - pattern.size();
			}
		}
		return -1;
	}
};