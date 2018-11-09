## -*- Makefile -*-


#### すべてのビルド・ターゲットで共有されるコンパイラとツールの定義 #####
CCC = g++
CXX = g++
BASICOPTS = -g
CCFLAGS = $(BASICOPTS)
CXXFLAGS = $(BASICOPTS)
CCADMIN = 


# ターゲット・ディレクトリを定義します。
TARGETDIR_sampleClass=build


all: $(TARGETDIR_sampleClass)/sampleClass

## ターゲット: sampleClass
OBJS_sampleClass =  \
	$(TARGETDIR_sampleClass)/SampleClass.o \
	$(TARGETDIR_sampleClass)/main.o
USERLIBS_sampleClass = $(SYSLIBS_sampleClass) 
DEPLIBS_sampleClass =  
LDLIBS_sampleClass = $(USERLIBS_sampleClass)


# リンクまたはアーカイブ
$(TARGETDIR_sampleClass)/sampleClass: $(TARGETDIR_sampleClass) $(OBJS_sampleClass) $(DEPLIBS_sampleClass)
	$(LINK.cc) $(CCFLAGS_sampleClass) $(CPPFLAGS_sampleClass) -o $@ $(OBJS_sampleClass) $(LDLIBS_sampleClass)


# ソース・ファイルを.oファイルにコンパイル
$(TARGETDIR_sampleClass)/SampleClass.o: $(TARGETDIR_sampleClass) SampleClass.cpp
	$(COMPILE.cc) $(CCFLAGS_sampleClass) $(CPPFLAGS_sampleClass) -o $@ SampleClass.cpp

$(TARGETDIR_sampleClass)/main.o: $(TARGETDIR_sampleClass) main.cpp
	$(COMPILE.cc) $(CCFLAGS_sampleClass) $(CPPFLAGS_sampleClass) -o $@ main.cpp



#### ターゲットは生成されたすべてのファイルを消去します ####
clean:
	rm -f \
		$(TARGETDIR_sampleClass)/sampleClass \
		$(TARGETDIR_sampleClass)/SampleClass.o \
		$(TARGETDIR_sampleClass)/main.o
	$(CCADMIN)
	rm -f -r $(TARGETDIR_sampleClass)


# ターゲット・ディレクトリの作成(必要な場合)
$(TARGETDIR_sampleClass):
	mkdir -p $(TARGETDIR_sampleClass)


# 依存性チェックを有効化
.KEEP_STATE:
.KEEP_STATE_FILE:.make.state.GNU-x86_64-MacOSX

