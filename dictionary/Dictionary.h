#pragma once

template <typename From, typename To>
class DictMatch {
	From word_;
	To translate_;
public:
	DictMatch() {} 
	DictMatch(const From& word, const To& translate) :
		word_(word), translate_(translate) {}

	DictMatch(const DictMatch& X) : word_(X.word_), translate_(X.translate_) {}
	DictMatch(DictMatch&& X) : word_(std::move(X.word_)),
		translate_(std::move(X.translate_)) {}

	DictMatch& operator=(const DictMatch& X) {
		if (this != &X) {
			word_ = X.word_;
			translate_ = X.translate_;
		}
		return*this;
	}

	DictMatch& operator=(DictMatch&& X) {
		if (this != &X) {
			word_ = std::move(X.word_);
			translate_ = std::move(X.translate_);
		}
		return*this;
	}

	const From& get_word() const { return word_; }
	const To& get_translate() const { return translate_; }
	bool operator==(const DictMatch& X)const { return word_ == X.word_; }
	bool operator!=(const DictMatch& X)const { return word_ != X.word_; }
	bool operator<(const DictMatch& X)const { return word_ < X.word_; }
};
