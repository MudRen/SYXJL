
// Room: /jingzhou/sishu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "私塾");
        set("long", @LONG
这里是私塾的讲堂，窗明几净，一尘不染。一位庄重严肃的老者正捋
着他的山羊胡须坐在太师椅上讲学，那就是本地大儒熊先生了。一张古意
盎然的书案放在熊先生的前面，案上摆着几本翻开了的线装书籍。下面的
学生们正随着熊先生摇头晃脑地背着八股文。老夫子刚奉了圣旨取得了颁
发学位的资格，就在门口树着书院新立的学位公告板(board)。
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "north" : __DIR__"xidajie",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}