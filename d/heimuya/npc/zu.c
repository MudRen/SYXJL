#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��ǧ��", ({ "zu qianqiu", "zu",}));
        set("nickname","�ƺ�����");
        set("long", 
"ֻ������Ƥ���ƣ�˫Ŀ�������������м���
���ӣ������������ȴͦ�Ÿ�����ӡ�\n");
        set("age", 80);        
        set("title",HIM"������̷�����̳��"NOR);       
        set("gender", "����");
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        
        set("max_qi", 600);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 600);
        set("jiali", 50);
        set("combat_exp", 100000);
        set("shen", -1000);


       
        set_skill("tmzhang",100);
        set_skill("pmshenfa",100);
         set_skill("tmdafa",100);

        map_skill("unarmed", "tmzhang");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");
create_family("�������",3,"����");
        setup();
}
