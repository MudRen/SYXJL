inherit NPC;
string *first_name =
({"��","��","��","��","��","��","��","��","��","��","��","��","��","��","ľ","ˮ","��","��"});
string *name_words =({"��","��","��","��","��", "��","��", 
"¹","��","��","�","��","��","��","Գ","��","��","ţ", "�","��","��","��"});

string *last_words=({"��"}); 
void create()
{
         string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
   name += last_words[random(sizeof(last_words))];
        set_name(name, ({ "ghost"}) );
        set("gender", "����" );
        set("age",40);
        set("str", 30);
        set("int", 20);
        set("per", 15);
        set("attitude", "heroism");
        set("combat_exp", 300000+random(200000));
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili",800);
        set("max_neili",800);
        set("jingli", 800);
        set("max_jingli", 800);
        set_skill("sword",100);
        set_skill("dodge",100);
        set_skill("parry",100);
   set_skill("quanzhen-jianfa", 100);
   map_skill("parry", "quanzhen-jianfa");
   map_skill("stick", "quanzhen-jianfa");
   set("HellZhen", 0);
        setup();
        carry_object("/clone/misc/cloth")->wear();
   carry_object("/d/city/obj/changjian")->wield();
}

void invocation(object who)
{
   object me=this_object();
   COMBAT_D->do_attack(me, who, query_temp("weapon"));
   destruct(me);
}
