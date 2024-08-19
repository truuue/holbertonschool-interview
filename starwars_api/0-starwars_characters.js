#!/usr/bin/node

const request = require("request");

function fetchCharacter(characterUrl) {
  return new Promise((resolve, reject) => {
    request(characterUrl, function (error, response, body) {
      if (error) {
        return reject(error);
      }
      const character = JSON.parse(body);
      resolve(character.name);
    });
  });
}

async function fetchCharactersInOrder(movieId) {
  const url = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

  request(url, async function (error, response, body) {
    if (error) {
      console.error("Error:", error);
      return;
    }

    const film = JSON.parse(body);
    const characters = film.characters;

    for (let i = 0; i < characters.length; i++) {
      try {
        const characterName = await fetchCharacter(characters[i]);
        console.log(characterName);
      } catch (error) {
        console.error("Error fetching character:", error);
      }
    }
  });
}

const movieId = process.argv[2];
fetchCharactersInOrder(movieId);
