
#include <ansi.h>
inherit NPC;

void create()
{
       set_name("��ɽ����",({"shoushan dizi", "dizi", "shoushan"}));     
       set("gender","Ů��");
       set("long","����һλ��ü�ɵ���ɽ���ӣ�\nСС��;͵���������ɽ�ŵ����Σ�\n�ɼ�����Ȼ������\n");
       set("max_qi" , 500);
       set("qi" , 500);
       set("max_jing" , 500);
       set("jing",500);
       set("max_neili" , 800);
       set("neili" , 1600);  
         set("combat_exp",10000);
       set_skill("force",50);
       set_skill("dodge",50);
       set_skill("parry",50);
       set_skill("sword",50);      
       set_skill("strike",50);  
       set_skill("fuliu-jian",50);
       set_skill("jinding-mianzhang",50);
       set_skill("zhutian",50);          
       set_skill("linji-zhuang",50);
       set("jiali" , 70);
                 
       map_skill("dodge","zhutian");
       map_skill("parry","fuliu-jian");
       map_skill("sword","fuliu-jian");
       map_skill("strike","jinding-mianzhang");
       map_skill("force","linji-zhuang");

       create_family("������", 6, "����");

       prepare_skill("jinding-mianzhang"); 
                                         
       setup();
       carry_object(__DIR__"obj/cloth")->wear();
       carry_object(__DIR__"obj/changjian")->wield();
}
 
