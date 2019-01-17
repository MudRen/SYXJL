
// Room: /jingzhou/shudian.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "书店");
        set("long", @LONG
这里是一家书店，由于本地人比较尊崇学者，好读书之风较盛。书架上
放满了各类书籍，你几乎可以在这里买到你需要的各类书籍，前来购书的人
络绎不绝。难怪古人发出：“唯楚有才”的感叹了。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"kedian",
                "south" : __DIR__"guangchang",
                "west"  : __DIR__"qianzhuang",
                "north" : __DIR__"beidajie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}