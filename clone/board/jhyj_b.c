 
#include <ansi.h>

inherit "/inherit/misc/bbsboard";

void create()
{
set_name(MAG"��"BBLU HIW"��¹����"NOR MAG"��"HIR"������"NOR, ({ HIC"BBS"NOR,"bbs"}) );
         set("location", "/d/city/kedian");
        set("board_id", "jhyj_b");
        set("long", "����һ������λ�������۵�"+HIC+" BBS "+NOR+"�塣\n\n��ʦ������"+HIW"mkgroup"NOR+" �� "+HIW"rmgroup"NOR+"ȥ
������ɾ��һ��������,��ҿ�����\n"
+HIW"read board"NOR+"ָ���Ķ�\n" );
        setup();
        set("capacity", 500);
        replace_program("/inherit/misc/bbsboard");
}


