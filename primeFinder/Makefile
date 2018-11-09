## -*- Makefile -*-

#### すべてのビルド・ターゲットで共有されるコンパイラとツールの定義 #####
CCC = g++
CXX = g++
BASICOPTS = -g
CCFLAGS = $(BASICOPTS)
CXXFLAGS = $(BASICOPTS)
CCADMIN = 


# ターゲット・ディレクトリを定義します。
TARGETDIR_prime=build


all: $(TARGETDIR_prime)/prime

## ターゲット: prime
OBJS_prime =  \
	$(TARGETDIR_prime)/main.o
USERLIBS_prime = $(SYSLIBS_prime) 
DEPLIBS_prime =  
LDLIBS_prime = $(USERLIBS_prime)


# リンクまたはアーカイブ
$(TARGETDIR_prime)/prime: $(TARGETDIR_prime) $(OBJS_prime) $(DEPLIBS_prime)
	$(LINK.cc) $(CCFLAGS_prime) $(CPPFLAGS_prime) -o $@ $(OBJS_prime) $(LDLIBS_prime)


# ソース・ファイルを.oファイルにコンパイル
$(TARGETDIR_prime)/main.o: $(TARGETDIR_prime) main.cpp
	$(COMPILE.cc) $(CCFLAGS_prime) $(CPPFLAGS_prime) -o $@ main.cpp



#### ターゲットは生成されたすべてのファイルを消去します ####
clean:
	rm -f \
		$(TARGETDIR_prime)/prime \
		$(TARGETDIR_prime)/main.o
	$(CCADMIN)
	rm -f -r $(TARGETDIR_prime)


# ターゲット・ディレクトリの作成(必要な場合)
$(TARGETDIR_prime):
	mkdir -p $(TARGETDIR_prime)


# 依存性チェックを有効化
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-x86_64-MacOSX

