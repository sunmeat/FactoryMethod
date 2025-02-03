namespace RampartCreaturesFactoryMethod
{
    abstract class Creature
    {
        public abstract string Name { get; }
        public abstract int Attack { get; }
        public abstract int Defense { get; }
        // ...
    }

    class Centaur : Creature
    {
        public override string Name => "Centaur";
        public override int Attack => 5;
        public override int Defense => 3;
    }

    class CentaurCaptain : Centaur
    {
        public override string Name => "Centaur Captain";
        public override int Attack => 7;
        public override int Defense => 4;
    }

    class Dwarf : Creature
    {
        public override string Name => "Dwarf";
        public override int Attack => 3;
        public override int Defense => 5;
    }

    class BattleDwarf : Dwarf
    {
        public override string Name => "Battle Dwarf";
        public override int Attack => 5;
        public override int Defense => 7;
    }

    class ElfArcher : Creature
    {
        public override string Name => "Elf Archer";
        public override int Attack => 5;
        public override int Defense => 3;
    }

    class RoyalElfArcher : ElfArcher
    {
        public override string Name => "Royal Elf Archer";
        public override int Attack => 7;
        public override int Defense => 4;
    }

    class Pegasus : Creature
    {
        public override string Name => "Pegasus";
        public override int Attack => 4;
        public override int Defense => 4;
    }

    class PegasusRider : Pegasus
    {
        public override string Name => "Pegasus Rider";
        public override int Attack => 6;
        public override int Defense => 5;
    }

    ////////////////////////////////////////////////////////////////////////////////

    abstract class CreatureFactory
    {
        // метод фабрики который будет создавать конкретное существо
        public abstract Creature CreateCreature(bool upgraded);
    }

    class CentaurFactory : CreatureFactory
    {
        public override Creature CreateCreature(bool upgraded)
        {
            return upgraded ? (Creature)new CentaurCaptain() : new Centaur();
        }
    }

    class DwarfFactory : CreatureFactory
    {
        public override Creature CreateCreature(bool upgraded)
        {
            return upgraded ? (Creature)new BattleDwarf() : new Dwarf();
        }
    }

    class ElfArcherFactory : CreatureFactory
    {
        public override Creature CreateCreature(bool upgraded)
        {
            return upgraded ? (Creature)new RoyalElfArcher() : new ElfArcher();
        }
    }

    class PegasusFactory : CreatureFactory
    {
        public override Creature CreateCreature(bool upgraded)
        {
            return upgraded ? (Creature)new PegasusRider() : new Pegasus();
        }
    }

    ////////////////////////////////////////////////////////////////////////////////

    class Program
    {
        static void Main()
        {
            // массив фабрик для каждого типа существа
            CreatureFactory[] factories = new CreatureFactory[]
            {
                new CentaurFactory(),
                new DwarfFactory(),
                new ElfArcherFactory(),
                new PegasusFactory()
            };

            foreach (var factory in factories)
            {
                Creature baseCreature = factory.CreateCreature(false); // базовая версия
                Creature upgradedCreature = factory.CreateCreature(true); // улучшеная версия

                Console.WriteLine($"{baseCreature.Name} - атака: {baseCreature.Attack}, защита: {baseCreature.Defense}");
                Console.WriteLine($"{upgradedCreature.Name} - атака: {upgradedCreature.Attack}, защита: {upgradedCreature.Defense}");
                Console.WriteLine(new string('-', 40));
            }
        }
    }
}

/*
1. создание существ не привязано к конкретным классам в основной программе (SRP)
2. если в будущем добавятся новые типы существ, не нужно будет модифицировать существующий код (OCP)
3. тип фабрики можно загружать из настроек или базы данных.
4. такой код будет проще тестировать фабрики в тестах, создавая заглушки (моки) вместо реальных классов.
5. на клиенте код стал чище, не нужно писать new Centaur() или new Dwarf()
*/