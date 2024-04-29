/*
* tn.h - 토큰 타입 enum 정의
* contributors: 김중현, 곽서진, 이나현, 김선영
* date: 04/30/2024
*/
enum tnumber {
	TEOF, TCONST, TELSE, TIF, TINT, TRETURN, TVOID, TWHILE, TEQUAL, TNOTEQU, TLESS, TGREAT, TLESSE, TGREATE, TNOT, TAND, TOR, TINC, TDEC, TADD, TSUB, TMUL, TDIV, TMOD, TASSIGN, TADDASSIGN, TSUBASSIGN, TMULASSIGN, TDIVASSIGN, TMODASSIGN, TLEFTPARENTHESIS, TRIGHTPARENTHESIS, TLEFTBRACE, TRIGHTBRACE, TLEFTBRACKET, TRIGHTBRACKET, TSEMICOLON, TCOMMA, TIDENT, TNUMBER, TRNUMBER, TERROR
};
