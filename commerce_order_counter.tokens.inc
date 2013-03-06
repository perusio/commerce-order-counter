<?php
/**
 * @file   commerce_order_counter.tokens.inc
 * @author Augustin Delaporte <guss.tissier@gmail.com>
 *         António P. P. Almeida <appa@perusio.net>
 * @date   Wed Mar  6 19:07:29 2013
 *
 * @brief  Token integration for commerce_order_counter.
 *
 */

/**
 * Implements hook_token_info().
 */
function commerce_order_counter_token_info() {
  $tokens['order-counter'] = array(
    'name' => t('Order counter'),
    'description' => t('Number or code for completed orders.'),
  );

  return array('tokens' => array('user' => $tokens),);
} // commerce_order_counter_token_info

/**
 * Implements hook_tokens().
 */
function commerce_order_counter_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  if ($type == 'user') {
    if (isset($tokens['order-counter'])) {
      $replacements[$tokens['order-counter']] = commerce_order_counter_get_order_counter();
    }
  }
  return $replacements;
} // commerce_order_counter_tokens
