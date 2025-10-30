-- Criação do banco de dados básico para um jogo de xadrez

CREATE TABLE jogadores (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nome TEXT NOT NULL,
    ranking INTEGER DEFAULT 1000
);

CREATE TABLE partidas (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    jogador_brancas_id INTEGER,
    jogador_pretas_id INTEGER,
    vencedor_id INTEGER,
    data_inicio DATETIME DEFAULT CURRENT_TIMESTAMP,
    data_fim DATETIME,
    FOREIGN KEY (jogador_brancas_id) REFERENCES jogadores(id),
    FOREIGN KEY (jogador_pretas_id) REFERENCES jogadores(id),
    FOREIGN KEY (vencedor_id) REFERENCES jogadores(id)
);

CREATE TABLE movimentos (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    partida_id INTEGER,
    numero_lance INTEGER,
    movimento TEXT,
    tempo DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (partida_id) REFERENCES partidas(id)
);
