## -*- Makefile -*-


#### すべてのビルド・ターゲットで共有されるコンパイラとツールの定義 #####
CCC = g++
CXX = g++
BASICOPTS = -g
CCFLAGS = $(BASICOPTS)
CXXFLAGS = $(BASICOPTS)
CCADMIN = 


# ターゲット・ディレクトリを定義します。
TARGETDIR_BlackJack=build


all: $(TARGETDIR_BlackJack)/BlackJack

## ターゲット: BlackJack
OBJS_BlackJack =  \
	$(TARGETDIR_BlackJack)/BlackJack.o \
	$(TARGETDIR_BlackJack)/main.o
USERLIBS_BlackJack = $(SYSLIBS_BlackJack) 
DEPLIBS_BlackJack =  
LDLIBS_BlackJack = $(USERLIBS_BlackJack)


# リンクまたはアーカイブ
$(TARGETDIR_BlackJack)/BlackJack: $(TARGETDIR_BlackJack) $(OBJS_BlackJack) $(DEPLIBS_BlackJack)
	$(LINK.cc) $(CCFLAGS_BlackJack) $(CPPFLAGS_BlackJack) -o $@ $(OBJS_BlackJack) $(LDLIBS_BlackJack)


# ソース・ファイルを.oファイルにコンパイル
$(TARGETDIR_BlackJack)/BlackJack.o: $(TARGETDIR_BlackJack) BlackJack.cpp
	$(COMPILE.cc) $(CCFLAGS_BlackJack) $(CPPFLAGS_BlackJack) -o $@ BlackJack.cpp

$(TARGETDIR_BlackJack)/main.o: $(TARGETDIR_BlackJack) main.cpp
	$(COMPILE.cc) $(CCFLAGS_BlackJack) $(CPPFLAGS_BlackJack) -o $@ main.cpp



#### ターゲットは生成されたすべてのファイルを消去します ####
clean:
	rm -f \
		$(TARGETDIR_BlackJack)/BlackJack \
		$(TARGETDIR_BlackJack)/BlackJack.o \
		$(TARGETDIR_BlackJack)/main.o
	$(CCADMIN)
	rm -f -r $(TARGETDIR_BlackJack)


# ターゲット・ディレクトリの作成(必要な場合)
$(TARGETDIR_BlackJack):
	mkdir -p $(TARGETDIR_BlackJack)


# 依存性チェックを有効化
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-x86_64-MacOSX

