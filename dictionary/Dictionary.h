#pragma once

template <typename From, typename To>
class Dictionary {
	From word_;
	To translate_;
public:
	Dictionary() : word_(""), translate_("") {}
	Dictionary(const From& word, const To& translate) :
		word_(word), translate_(translate) {}

	Dictionary(const Dictionary& X) : word_(X.word_), translate_(X.translate_) {}
	Dictionary(Dictionary&& X) : word_(std::move(X.word_)),
		translate_(std::move(X.translate_)) {}

	Dictionary& operator=(const Dictionary& X) {
		if (this != &X) {
			word_ = X.word_;
			translate_ = X.translate_;
		}
		return*this;
	}

	Dictionary& operator=(Dictionary&& X) {
		if (this != &X) {
			word_ = std::move(X.word_);
			translate_ = std::move(X.translate_);
		}
		return*this;
	}

	const From& get_word() const { return word_; }
	const To& get_translate() const { return translate_; }
	bool operator==(const Dictionary& X)const { return word_ == X.word_; }
	bool operator!=(const Dictionary& X)const { return word_ != X.word_; }
	bool operator<(const Dictionary& X)const { return word_ < X.word_; }
};
