
// Room: /chang'an/xuetang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "学堂");
        set("long", @LONG
这里是长安的学堂，窗明几净，一尘不染。一位庄重严肃的老学究正
端坐在一把太师椅上讲学。在他的两侧坐满了求学的学生。一张古意盎然
的书案放在老先生的前面，案上摆着几本翻开了的线装书籍。在他下方坐
满了求学的学生。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "south" : __DIR__"nanyuanmen",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}