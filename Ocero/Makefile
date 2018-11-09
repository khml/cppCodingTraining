## -*- Makefile -*-
##
## ユーザー: keiichi
## 日時: Nov 9, 2018 10:38:57 PM
## Makefile created by Oracle Developer Studio.
##
## このファイルは自動的に生成されます
##


#### すべてのビルド・ターゲットで共有されるコンパイラとツールの定義 #####
CCC = g++
CXX = g++
BASICOPTS = -g
CCFLAGS = $(BASICOPTS)
CXXFLAGS = $(BASICOPTS)
CCADMIN = 


# ターゲット・ディレクトリを定義します。
TARGETDIR_Ocero=build


all: $(TARGETDIR_Ocero)/Ocero

## ターゲット: Ocero
OBJS_Ocero =  \
	$(TARGETDIR_Ocero)/Ocero.o \
	$(TARGETDIR_Ocero)/main.o
USERLIBS_Ocero = $(SYSLIBS_Ocero) 
DEPLIBS_Ocero =  
LDLIBS_Ocero = $(USERLIBS_Ocero)


# リンクまたはアーカイブ
$(TARGETDIR_Ocero)/Ocero: $(TARGETDIR_Ocero) $(OBJS_Ocero) $(DEPLIBS_Ocero)
	$(LINK.cc) $(CCFLAGS_Ocero) $(CPPFLAGS_Ocero) -o $@ $(OBJS_Ocero) $(LDLIBS_Ocero)


# ソース・ファイルを.oファイルにコンパイル
$(TARGETDIR_Ocero)/Ocero.o: $(TARGETDIR_Ocero) Ocero.cpp
	$(COMPILE.cc) $(CCFLAGS_Ocero) $(CPPFLAGS_Ocero) -o $@ Ocero.cpp

$(TARGETDIR_Ocero)/main.o: $(TARGETDIR_Ocero) main.cpp
	$(COMPILE.cc) $(CCFLAGS_Ocero) $(CPPFLAGS_Ocero) -o $@ main.cpp



#### ターゲットは生成されたすべてのファイルを消去します ####
clean:
	rm -f \
		$(TARGETDIR_Ocero)/Ocero \
		$(TARGETDIR_Ocero)/Ocero.o \
		$(TARGETDIR_Ocero)/main.o
	$(CCADMIN)
	rm -f -r $(TARGETDIR_Ocero)


# ターゲット・ディレクトリの作成(必要な場合)
$(TARGETDIR_Ocero):
	mkdir -p $(TARGETDIR_Ocero)


# 依存性チェックを有効化
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-x86_64-MacOSX

