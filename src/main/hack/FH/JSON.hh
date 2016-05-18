<?hh // strict
namespace FH;
use DateTime;
use DateTimeInterface;

final class JSON {
    private function __construct(private mixed $value) { }

    public static function null  ():          JSON { return new JSON(null); }
    public static function bool  (bool $v):   JSON { return new JSON($v); }
    public static function num   (num $v):    JSON { return new JSON($v); }
    public static function string(string $v): JSON { return new JSON($v); }

    public static function dateTime(DateTimeInterface $v): JSON {
        return new JSON($v->format(DateTime::ISO8601));
    }

    public static function array_(ImmVector<JSON> $vs): JSON {
        return new JSON($vs->map(function($v) { return $v->value; })->toArray());
    }

    public static function object(ImmMap<string, JSON> $vs): JSON {
        return new JSON((object)$vs->map(function($v) { return $v->value; })->toArray());
    }

    public function encode(): string {
        return json_encode($this->value);
    }
}
